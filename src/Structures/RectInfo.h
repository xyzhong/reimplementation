#ifndef _RECTINFO_H_
#define _RECTINFO_H_

/**
  *@file		RectInfo.h
  *
  *@author		cxgAlleria
  *
  *@brief		
  *
  *@date		2016-03-03 19:56
  *
  *@history
  *<2016/03/03 20:22>tested.
  */

class RectInfo{
	/*FIELDS*/
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	/*METHODS*/
public:
	int getX() const{
		return this->m_x;
	}
	void setX(int x) {
		//Validate the arg if necessary
		this->m_x = x;
	}
	int getY() const{
		return this->m_y;
	}
	void setY(int y) {
		//Validate the arg if necessary
		this->m_y = y;
	}
	int getWidth() const{
		return this->m_width;
	}
	void setWidth(int width) {
		//Validate the arg if necessary
		this->m_width = width;
	}
	int getHeight() const{
		return this->m_height;
	}
	void setHeight(int height) {
		//Validate the arg if necessary
		this->m_height = height;
	}
	/*CON(DE)STRUTURES*/
public:
	RectInfo(int x, int y, int width, int height)
		: m_x(x), m_y(y), m_width(width), m_height(height) {
		//your own implementation
	}
	virtual ~RectInfo() {}
};

#endif // ! _RECTINFO_H_
