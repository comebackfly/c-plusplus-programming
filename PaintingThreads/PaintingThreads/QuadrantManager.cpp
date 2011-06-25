#include "StdAfx.h"
#include "QuadrantManager.h"
//#include "LockClasses.h"


QuadrantManager::QuadrantManager(void)
{
	this->topLeftLocked=false;
	this->topRightLocked=false;
	this->bottomLeftLocked=false;
	this->bottomRightLocked=false;
	this->overallLocked=false;

	this->topLeftQuadrant = new CReadWriteLock();
	this->topRightQuadrant = new CReadWriteLock();
	this->bottomLeftQuadrant = new CReadWriteLock();
	this->bottomRightQuadrant = new CReadWriteLock();
	this->overall = new CReadWriteLock();
}


QuadrantManager::~QuadrantManager(void)
{
}

bool QuadrantManager::isLocked(int quadrantIndex){

	bool isLocked=false;

	switch(quadrantIndex){

	case 1:
		isLocked=topLeftLocked;

	case 2:
		isLocked=topRightLocked;

	case 3:
		isLocked=bottomLeftLocked;

	case 4:
		isLocked=bottomRightLocked;

	case 5:
		isLocked=overallLocked;
	}

	return isLocked;
}

void QuadrantManager::getTopLeftQuadrant(){

	topLeftQuadrant->lockWriter();
}

void QuadrantManager::getTopRightQuadrant(){

	topRightQuadrant->lockWriter();
}

void QuadrantManager::getBottomLeftQuadrant(){

	bottomLeftQuadrant->lockWriter();
}

void QuadrantManager::getBottomRightQuadrant(){

	bottomRightQuadrant->lockWriter();
}

void QuadrantManager::getOverall(){

	overall->lockWriter();
}

void QuadrantManager::returnTopLeftQuadrant(){

	topLeftQuadrant->unlockWriter();
}

void QuadrantManager::returnTopRightQuadrant(){

	topRightQuadrant->unlockWriter();
}

void QuadrantManager::returnBottomLeftQuadrant(){

	bottomLeftQuadrant->unlockWriter();
}

void QuadrantManager::returnBottomRightQuadrant(){

	bottomRightQuadrant->unlockWriter();
}

void QuadrantManager::returnOverall(){

	overall->unlockWriter();
}