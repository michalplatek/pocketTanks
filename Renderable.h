#pragma once
class Renderable
{
public:
	Renderable();
	virtual ~Renderable();

	virtual void render() = 0;
	virtual void renderAtBodyPosition() = 0;
};

