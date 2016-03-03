#ifndef _DESCMAT_H_
#define _DESCMAT_H_

/**
  *@file		DescMat.h
  *
  *@author		cxgAlleria
  *
  *@brief		
  *
  *@date		2016-03-03 19:56
  *
  *@history
  *<2016/03/03 20:11>updated, to be tested.
  *<2016/03/03 20:18>tested.
  */

class DescMat{
	/*FIELDS*/
private:
	int m_width;
	int m_height;
	int m_nBins;
	float* m_desc;
	/*METHODS*/
public:
	int getWidth() const{
		return this->m_width;
	}
	void setWidth(int width) {
		//Validate the arg if necessary
		if(this->m_width != width){
			this->m_width = width;
			notify();
		}
	}
	int getHeight() const{
		return this->m_height;
	}
	void setHeight(int height) {
		//Validate the arg if necessary
		if(this->m_height != height){
			this->m_height = height;
			notify();
		}
	}
	int getNBins() const{
		return this->m_nBins;
	}
	void setNBins(int nBins) {
		//Validate the arg if necessary
		if(this->m_nBins != nBins){
			this->m_nBins = nBins;
			notify();
		}
	}
	/*CON(DE)STRUTURES*/
public:
	DescMat(int width, int height, int nBins)
		: m_width(width), m_height(height), m_nBins(nBins), m_desc(nullptr) {
		//your own implementation
		notify();
	}
	virtual ~DescMat() {}
	float & at(int w, int h, int bin){
		return this->m_desc[(w * m_height + h) * m_nBins + bin];
	}
protected:
	void notify(){
		if(this->m_desc != nullptr){
			delete [] this->m_desc;
			this->m_desc = nullptr;
		}
		int _sz = this->m_width * this->m_height * this->m_nBins;
		this->m_desc = new float [_sz];
		for(int __iterator = 0; __iterator < _sz; ++ __iterator){
			this->m_desc[__iterator] = 0;
		}
	}
};

#endif // ! _DESCMAT_H_
