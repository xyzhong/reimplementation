#ifndef _DESCMAT_H_
#define _DESCMAT_H_

/**
 * @file		DescMat.h
 *
 * @author		cxgAlleria
 *
 * @brief		the descriptor mode
 *
 * @date		<2016/03/04 20:51>
 * 
 * @history
 * <2016/03/04 20:51>start implementation
 * <2016/03/05 14:14>done & validated. to be tested.
 */

#include <cassert>

class DescMat{
public:
	DescMat(int width, int height, int nBins)
	: m_width(width), m_height(height), m_nBins(nBins), m_desc(new float [width * height * nBins]){
		
	}
	virtual ~DescMat(){
		if(this->m_desc != nullptr){
			delete [] this->m_desc;
			this->m_desc = nullptr;
		}
	}
	float & at(int w, int h, int bin){
	assert(w >= 0 && w < this->m_width);
	assert(h >= 0 && h < this->m_height);
	assert(bin >= 0 && bin < this->m_nBins);
	return this->m_desc[(w * this->m_height + h) * this->m_nBins + bin];
	}
	/**
	 * @brief		the descriptor is kind of a 3-dimension array
	 */
private:
	int m_width, m_height, m_nBins;
	float * m_desc;
};
#endif// ! _DESCMAT_H_
