#pragma once
#ifndef __TRACK_H
#define __TRACK_H
#include "stack.h"
arrayStack<int> *track;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;
void outputFromHoldingTrack()
{
	track[itsTrack].pop();
	std::cout << "Move car" << smallestCar << "from holding track " << itsTrack << " to output track " << std::endl;

	smallestCar = numberOfCars + 2;
	for(int i;i<=numberOfTracks;i++)
		if (!track[i].empty() && (track[i].top() < smallestCar))
		{
			smallestCar = track[i].top();
			itsTrack = i;
		}
}
bool putInHoldingTrack(int c)
{
	int bestTrack = 0;
	int bestTop = numberOfCars + 1;

	for (int i = 1; i <= numberOfTracks; i++)
		if (!track[i].empty())
		{
			int topCar = track[i].top();
			if (c < topCar&&topCar < bestTop)
			{
				bestTop = topCar;
				bestTrack = i;
			}
		}
		else
			if (bestTrack == 0)
				bestTrack = i;
	if (bestTrack == 0)
		return false;

	track[bestTrack].push(c);
	std::cout << "Moce car " << c << "from input track" << "to holding track " << bestTrack << std::endl;

	if (c < smallestCar)
	{
		smallestCar = c;
		itsTrack = bestTrack;
	}
}
bool realroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
{
	numberOfCars = theNumberOfCars;
	numberOfTracks = theNumberOfTracks;

	track = new arrayStack<int>[numberOfTracks + 1];
	int nextCarToOutput = 1;
	smallestCar = numberOfCars + 1;
	
	for (int i = 1; i <= numberOfCars; i++)
	{
		if (inputOrder[i] == nextCarToOutput)
		{
			std::cout << "Move car" << inputOrder[i] << "from input track to output track" << std::endl;
			nextCarToOutput++;

			while (smallestCar == nextCarToOutput)
			{
				outputFromHoldingTrack();
				nextCarToOutput++;
			}
		}
		else
			if (!putInHoldingTrack(inputOrder[i]))
				return false;
		return true;
	}
}
#endif