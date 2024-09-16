#include "Path.h"

PathManager* PathManager::instance = nullptr;

Path::Path(int point_count) : points()
{
	for (int i = 0; i < point_count; i++)
	{
		points.push_back({ 0,0 });
	}
}

Path::~Path()
{

}

void Path::SetPoint(int index, Vector2f point)
{
	if (index >= 0 && index < points.size())
	{
		points[index] = point;
	}
}

Vector2f Path::GetPoint(int index)
{
	if (index >= 0 && index < points.size())
	{
		return points[index];
	}
	else
	{
		return { 0,0 };
	}
}

bool Path::isLastPoint(int index)
{
	return index == points.size() - 1;
}

PathManager::PathManager() : paths()
{

}

PathManager::~PathManager()
{
	for (auto p : paths) delete p;
	paths.clear();
}

PathManager* PathManager::GetInstance()
{
	if (instance == nullptr) instance = new PathManager();
	return instance;
}

void PathManager::Destroy()
{
	delete instance;
}

Path* PathManager::GetPath(int index)
{
	if (index < 0 || index >= paths.size()) return nullptr;
	return paths[index];
}

void PathManager::AddPath(Path* path)
{
	paths.push_back(path);
}