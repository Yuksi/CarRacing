#ifndef ACTIVE_H
#define ACTIVE_H

class Active
{
public:
	Active();
	inline int getPositionBottomX() const;
	inline int getPositionLeftY() const;
	inline int getSizeX() const;
	inline int getSizeY() const;
	virtual void print();
protected:
	int positionLeftY_;
	int positionBottomX_;
	int sizeX_;
	int sizeY_;
	void putConsoleCursorToXY(const int x, const int y);
};

inline int Active::getPositionBottomX() const {
	return positionBottomX_;
}
inline int Active::getPositionLeftY() const {
	return positionLeftY_;
}
inline int Active::getSizeX() const {
	return sizeX_;
}
inline int Active::getSizeY() const {
	return sizeY_;
}

#endif BLOCK_H