#ifndef ENEMY_H
#define ENEMY_H

#include "Active.h"
class Enemy : public Active
{
public:
	Enemy();
	virtual ~Enemy();
	inline void moveDown();
	bool isNoMatterOfPosition() const;
	bool isRightPosition() const;
protected:
	bool isNoMatterOfPosition_;
	bool isRightPosition_;
};

inline void Enemy::moveDown() {
	positionBottomX_++;
}

inline bool Enemy::isNoMatterOfPosition() const {
	return isNoMatterOfPosition_;
}
inline bool Enemy::isRightPosition() const {
	return isRightPosition_;
}

#endif ENEMY_H