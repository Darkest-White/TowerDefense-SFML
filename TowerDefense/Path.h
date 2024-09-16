#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

class Path
{
private:
	vector<Vector2f> points;

public:
	Path(int point_count);
	~Path();

	void SetPoint(int index, Vector2f point);
	Vector2f GetPoint(int index);

	bool isLastPoint(int index);
};

class PathManager
{
private:
	vector<Path*> paths;

	static PathManager* instance;

	PathManager();
	~PathManager();

public:
	static PathManager* GetInstance();
	static void Destroy();

	Path* GetPath(int index);
	void AddPath(Path* path);
};