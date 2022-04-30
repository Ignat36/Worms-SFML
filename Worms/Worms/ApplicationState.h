#pragma once
class ApplicationState
{
public:
	virtual void ProcessInput() = 0;
	virtual void UpdateObjects() = 0;
	virtual void RenderObjects() = 0;
};

