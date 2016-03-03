#ifndef _TRACKINFO_H_
#define _TRACKINFO_H_

/**
  *@file		TrackInfo.h
  *
  *@author		cxgAlleria
  *
  *@brief		
  *
  *@date		2016-03-03 19:56
  *
  *@history
  *<2016/03/03 20:25>tested.
  */

class TrackInfo{
	/*FIELDS*/
private:
	int m_length;
	int m_gap;
	/*METHODS*/
public:
	int getLength() const{
		return this->m_length;
	}
	void setLength(int length) {
		//Validate the arg if necessary
		this->m_length = length;
	}
	int getGap() const{
		return this->m_gap;
	}
	void setGap(int gap) {
		//Validate the arg if necessary
		this->m_gap = gap;
	}
	/*CON(DE)STRUTURES*/
public:
	TrackInfo(int length, int gap)
		: m_length(length), m_gap(gap) {
		//your own implementation
	}
	virtual ~TrackInfo() {}
};

#endif // ! _TRACKINFO_H_
