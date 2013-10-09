//class vector 2d
//Last Edit 10/8/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

class vector2d
{
public:
	vector2d() {x = 0; y = 0;}
	~vector2d(){}

	float GetX() {return x;}
	float GetY() {return y;}

	void SetX(int nextX) {x = nextX;}
	void SetY(int nextY) {y = nextY;}

	vector2d operator+ (const vector2d &w)
	{
		vector2d temp;
		temp.x = this->x + w.x;
		temp.y = this->x + w.y;
		return temp;
	}

	vector2d operator+ (float s) //scalar add
	{
		vector2d temp;
		temp.x = this->x + s; 
		temp.y = this->y + s;
		return temp;
	}

	vector2d operator- (const vector2d &w)
	{
		vector2d temp;
		temp.x = this->x - w.x;
		temp.y = this->x - w.y;
		return temp;
	}

	vector2d operator- (float s) //scalar sub
	{
		vector2d temp;
		temp.x = this->x - s; 
		temp.y = this->y - s;
		return temp;
	}

	vector2d operator* (float s) //scalar multi
	{
		vector2d temp;
		temp.x = this->x * s; 
		temp.y = this->y * s;
		return temp;
	}

	float dotProduct(vector2d &a, vector2d &b) 
	{ 
		return (a.x * b.x + a.y * b.y); 
	} 

private:
	float x;
	float y;
};

#endif