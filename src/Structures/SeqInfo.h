#ifndef _SEQINFO_H_
#define _SEQINFO_H_

/**
  *@file		SeqInfo.h
  *
  *@author		cxgAlleria
  *
  *@brief		
  *
  *@date		2016-03-03 19:56
  *
  *@history
  *<2016/03/03 20:24>tested.
  */

class SeqInfo{
	/*FIELDS*/
private:
	int m_width;
	int m_height;
	int m_length;
	/*METHODS*/
public:
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
	int getLength() const{
		return this->m_length;
	}
	void setLength(int length) {
		//Validate the arg if necessary
		this->m_length = length;
	}
	/*CON(DE)STRUTURES*/
public:
	SeqInfo(int width, int height, int length)
		: m_width(width), m_height(height), m_length(length) {
		//your own implementation
	}
	virtual ~SeqInfo() {}
};

#endif // ! _SEQINFO_H_
