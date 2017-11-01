#ifndef ACTIVE_H
#define ACTIVE_H

class Active
{
public:
	Active();
	inline int getPositionBottomX() const;
	inline int getPositionLeftY() const;
	virtual void print();
protected:
	int positionLeftY_;
	int positionBottomX_;
	void putConsoleCursorToXY(const int x, const int y);
};

inline int Active::getPositionBottomX() const {
	return positionBottomX_;
}
inline int Active::getPositionLeftY() const {
	return positionLeftY_;
}

#endif BLOCK_H