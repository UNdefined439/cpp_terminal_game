#pragma once

#include "effects.h"

class Frozen : public Effects {
public:
	Frozen(int length);

	void apply(Players& player) override;
	bool undo(Players& player) override;
};

class Invisible : public Effects {
public:
	Invisible(int length);

	void apply(Players& player) override;
	bool undo(Players& player) override;
};

class MaxHealthBoost : public Effects {
public:
	MaxHealthBoost(int length, int boost);

	void apply(Players& player) override;
	bool undo(Players& player) override;
};

class DamageBoost : public Effects {
public:
	DamageBoost(int length, int boost);

	void apply(Players& player) override;
	bool undo(Players& player) override;
};

class BlockBoost : public Effects {
public:
	BlockBoost(int length, int boost);

	void apply(Players& player) override;
	bool undo(Players& player) override;
};