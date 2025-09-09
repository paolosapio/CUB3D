#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.hpp"

// COMPILE: g++ -o raycast -Iinc src/main.cpp -lX11 -lGL -lpthread -lpng

class Example: public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Raycast with DDA Algorithm";
	}
	olc::vf2d vPlayer = {0,0}; //player location
	olc::vi2d vMapSize = {32,30}; // map size
	olc::vi2d vCellSize = {16,16}; // size of each cell
	std::vector<int> vecMap;

	bool OnUserCreate() override
	{
		vecMap.resize(vMapSize.x * vMapSize.y);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		olc::vf2d vMouse = {float(GetMouseX()), float(GetMouseY())};
		olc::vf2d vMouseCell = {(vMouse.x / vCellSize.x), (vMouse.y / vCellSize.y)};
		olc::vi2d vCell = {(int)(vMouse.x / vCellSize.x), (int)(vMouse.y / vCellSize.y)};

		if (GetMouse(1).bHeld)
			vecMap[vCell.y * vMapSize.x + vCell.x] = 1;
		
		// Modify player's position
		if (GetKey(olc::Key::W).bHeld) vPlayer.y -= 25.0f * fElapsedTime; //speed constant * fElapsedTime. This makes it consistent by frame (?).
		if (GetKey(olc::Key::A).bHeld) vPlayer.x -= 25.0f * fElapsedTime;
		if (GetKey(olc::Key::S).bHeld) vPlayer.y += 25.0f * fElapsedTime;
		if (GetKey(olc::Key::D).bHeld) vPlayer.x += 25.0f * fElapsedTime;

		//DDA ALGORITHM ----------------------------------------

		//Form ray cast from player into scene.
		olc::vf2d vRayStart = vPlayer; // Initial coordinates. //!start
		olc::vf2d vRayDir = (vMouseCell - vPlayer).norm(); // Ending coordinates. 
		std::cout << "--->" << vRayDir.x << "  " << vRayDir.y << std::endl;

		//pitágoras para determinar el aumento de la hipotenusa:
		// h = sqrt(x² + y²) -> 
		//		sqrt(1 + (dy/dx)²) (aumento en x) || sqrt(1 + (dx/dy)²) (aumento en y)

		olc::vf2d vRayUnitStepSize = { 
			sqrt(1 + (vRayDir.y / vRayDir.x) * (vRayDir.y / vRayDir.x)),
			 sqrt(1 + (vRayDir.x / vRayDir.y) * (vRayDir.x / vRayDir.y))};

		std::cout << "vRayUnitStepSize.x" << vRayUnitStepSize.x << "\n "<< vRayUnitStepSize.y << "\n\n";

		olc::vi2d vMapCheck = {(int)vRayStart.x, (int)vRayStart.y}; //to keep track of which cell the character is in.
		olc::vf2d vRayLength1D; // to acumulate the length of the ray on both axis.
		// We will need to manually calculate the length of the ray till the first intersection, since
		// most probably the character will be inbetween tiles.
		// It needs to be positive obvs!!.

		olc::vi2d vStep;
		// To keep track in wich direction we will be moving both on x and y.
		// and to save the ray length on both axis when we start on an unaligned position.
		if (vRayDir.x < 0)
		{
			vStep.x = -1;
			vRayLength1D.x = (vRayStart.x - (float)vMapCheck.x) * vRayUnitStepSize.x;
		}
		else
		{
			vStep.x = 1;
			vRayLength1D.x = ((float)(vMapCheck.x + 1) - vRayStart.x) * vRayUnitStepSize.x;
		}

		if (vRayDir.y < 0)
		{
			vStep.y = -1;
			vRayLength1D.y = (vRayStart.y - (float)vMapCheck.y) * vRayUnitStepSize.y;
		}
		else
		{
			vStep.y = 1;
			vRayLength1D.y = ((float)(vMapCheck.y + 1) - vRayStart.y) * vRayUnitStepSize.y;
		}

		bool wallFound = false;
		float fMaxDistance = 100.0f;
		float fDistance = 0.0f;
		while(wallFound == false && fDistance < fMaxDistance)
		{
		//	printf("vRayLength1D.x = %f, vRayLength1D.y = %f.\n", vRayLength1D.x, vRayLength1D.y);
			//We will work on whichever rayLength is shorter, like we saw on the video.
			if (vRayLength1D.x < vRayLength1D.y)
			{
				vMapCheck.x += vStep.x; // this will add or substract 1 'x' unit based on the direction of the ray.
				fDistance = vRayLength1D.x; // to  update fDistance.
				vRayLength1D.x += vRayUnitStepSize.x; // We already are on an intersection so yeah, we just add the gradient based on the x axis.
			}
			else
			{
				vMapCheck.y += vStep.y; // this will add or substract 1 'y' unit based on the direction of the ray.
				fDistance = vRayLength1D.y; // to  update fDistance.
				vRayLength1D.y += vRayUnitStepSize.y; // Same as up there but with the y axis.
			}

		//	printf("fDistance = %f - fMaxDistance = %f\n", fDistance, fMaxDistance);
			if (vMapCheck.x >= 0 && vMapCheck.x < vMapSize.x && vMapCheck.y >= 0 && vMapCheck.y < vMapSize.y)
			{
				if (vecMap[vMapCheck.y * vMapSize.x + vMapCheck.x] == 1)
				{
					std::cout << "Y = " << vMapCheck.y << "X = " << vMapCheck.x << std::endl; 
					//A collision has ocurred.
		//			printf("collision has ocurred!\n");
					wallFound = true;
				}
			}
		}
		//printf("salimos del bucle weeee\n");
		olc::vf2d vCollision;
		if (wallFound == true)
		{
			vCollision = vRayStart + vRayDir * fDistance; // this will give us the ending point.
		}






		Clear(olc::BLACK);
		//draw map
		for (int y = 0; y < vMapSize.y; y++)
		{
			for (int x = 0; x < vMapSize.x; x++)
			{
				int cell = vecMap[y * vMapSize.x + x];
				if (cell == 1)
					FillRect(x * vCellSize.x, y * vCellSize.y, vCellSize.x, vCellSize.y, olc::BLUE);
				DrawRect(x * vCellSize.x, y * vCellSize.y, vCellSize.x, vCellSize.y, olc::DARK_GREY);
			}
		}
		if (GetMouse(0).bHeld)
		{
			DrawLine(vPlayer.x * vCellSize.x, vPlayer.y * vCellSize.y,
				vMouse.x, vMouse.y, olc::WHITE, 0xF0F0F0F0);
			if (wallFound == true)
			{
				DrawCircle(vCollision.x * vCellSize.x, vCollision.y * vCellSize.y, 4.0f, olc::YELLOW);
			}
		}

		FillCircle(vPlayer.x * vCellSize.x, vPlayer.y * vCellSize.y, 4.0f, olc::RED);

		FillCircle(vMouse.x, vMouse.y, 4.0f, olc::GREEN);
		return (true);
	}
};


int main()
{
	Example demo;
	if (demo.Construct(480, 400, 2, 2))
	{

		demo.Start();
	}
	return 0;
}