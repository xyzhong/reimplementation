#ifndef _INFO_H_
#define _INFO_H_

/**
 * @file		Info.h
 * 
 * @author		cxgAlleria
 *
 * @brief		auxiliary structures
 *
 * @date		2016/03/04 19:50
 *
 * @history
 *<2016/03/04 19:50>start implementation
 */

class Info{
public:
	Info(){
	}
	virtual ~Info(){
	}
};

class RectInfo 
	: public Info{
public:
	RectInfo(int x, int y, int width, int height)
	:m_x(x), m_y(y), m_width(width), m_height(height){
	}
	virtual ~RectInfo(){
	}
	/**
	 *	@brief		the topleft coordinate of the rectangle and the size
	 */
	int m_x, m_y;
	int m_width, m_height;
};

class SeqInfo
	: public Info{
public:
	SeqInfo(int width, int height, int length)
	: m_width(width), m_height(height), m_length(length){
	}
	virtual ~SeqInfo(){
	}
	/*
	 *	@brief	the size of the video cube
	 */
	int m_width, m_height, m_length;
};

class TrackInfo
	: public Info{
public:
	TrackInfo(int length, int gap)
	: m_length(length), m_gap(gap){
	}
	virtual ~TrackInfo(){
	}
	/**
	 *	@brief	the length of trajectories and the gap between smapling
	 */
	int m_length, m_gap;
};

class DescInfo
	: public Info{
public:
	DescInfo(int nBins, bool isHof, int nxCells, int nyCells, int ntCells, int height, int width)
	: m_nBins(nBins), m_isHof(isHof), m_nxCells(nxCells), m_nyCells(nyCells), m_ntCells(ntCells), m_height(height), m_width(width){
	}
	virtual ~DescInfo(){
	}

	int dim(){
		return m_nxCells * m_nyCells * m_nBins;
	}
	/**
	 *	@brief	the bin count of the descriptors, flag to indicate hof, the partition principle for the trajectory cube, the size of the block for computing the descriptor
	 */
	int m_nBins, m_nxCells, m_nyCells, m_ntCells, m_height, m_width;
	bool m_isHof;
};

class InfoBuilder{
public:
	static Info * createRectInfo(int x, int y, int w, int h){
		return new RectInfo(x, y, w, h);
	}

	static Info * createSeqInfo(int w, int h, int l){
		return new SeqInfo(w, h, l);
	}

	static Info * createTrackInfo(int lenght, int gap){
		return new TrackInfo(lenght, gap);
	}

	static Info * createDescInfo(int nb, bool isHof, int nx, int ny, int nt, int h, int w){
		return new DescInfo(nb, isHof, nx, ny, nt, h, w);
	}
};

#endif// ! _INFO_H_
