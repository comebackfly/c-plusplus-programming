#pragma once
#include "LockClasses.h"


class QuadrantManager
{
public:
	QuadrantManager(void);
	~QuadrantManager(void);

	bool isLocked(int quadrantIndex);

	void getTopLeftQuadrant();
	void getTopRightQuadrant();
	void getBottomLeftQuadrant();
	void getBottomRightQuadrant();
	void getOverall();

	void returnTopLeftQuadrant();
	void returnTopRightQuadrant();
	void returnBottomLeftQuadrant();
	void returnBottomRightQuadrant();
	void returnOverall();

private:
	bool topLeftLocked;
	bool topRightLocked;
	bool bottomLeftLocked;
	bool bottomRightLocked;
	bool overallLocked;

	CReadWriteLock* topLeftQuadrant;
	CReadWriteLock* topRightQuadrant;
	CReadWriteLock* bottomLeftQuadrant;
	CReadWriteLock* bottomRightQuadrant;
	CReadWriteLock* overall;

};

