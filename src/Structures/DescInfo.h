#ifndef _DESCINFO_H_
#define _DESCINFO_H_

/**
  *@file		DescInfo.h
  *
  *@author		cxgAlleria
  *
  *@brief		
  *
  *@date		2016-03-03 19:43
  *
  *@history
  *<2016/03/02 20:01>updated, to be tested.
  *<2016/03/03 20:21>tested.
  */

class DescInfo{
	/*FIELDS*/
private:
	int m_nBins;
	bool m_isHof;
	int m_nxCells;
	int m_nyCells;
	int m_ntCells;
	int m_height;
	int m_width;
	/*METHODS*/
public:
	int getNBins() const{
		return this->m_nBins;
	}
	void setNBins(int nBins) {
		//Validate the arg if necessary
		this->m_nBins = nBins;
	}
	bool getIsHof() const{
		return this->m_isHof;
	}
	void setIsHof(bool isHof) {
		//Validate the arg if necessary
		this->m_isHof = isHof;
	}
	int getNXCells() const{
		return this->m_nxCells;
	}
	void setNCXells(int nxCells) {
		//Validate the arg if necessary
		this->m_nxCells = nxCells;
	}
	int getNYCells() const{
		return this->m_nyCells;
	}
	void setNYCells(int nyCells) {
		//Validate the arg if necessary
		this->m_nyCells = nyCells;
	}
	int getNTCells() const{
		return this->m_ntCells;
	}
	void setNTCells(int ntCells) {
		//Validate the arg if necessary
		this->m_ntCells = ntCells;
	}
	int getDim() const{
		return this->m_nBins * this->m_nxCells * this->m_nyCells;
	}
	int getHeight() const{
		return this->m_height;
	}
	void setHeight(int height) {
		//Validate the arg if necessary
		this->m_height = height;
	}
	int getWidth() const{
		return this->m_width;
	}
	void setWidth(int width) {
		//Validate the arg if necessary
		this->m_width = width;
	}
	/*CON(DE)STRUTURES*/
public:
	DescInfo(int nBins, bool isHof, int nxCells, int nyCells, int ntCells, int height, int width)
		: m_nBins(nBins), m_isHof(isHof), m_nxCells(nxCells), m_nyCells(nyCells), m_ntCells(ntCells), m_height(height), m_width(width) {
		//your own implementation
	}
	virtual ~DescInfo() {}
};

#endif // ! _DESCINFO_H_
