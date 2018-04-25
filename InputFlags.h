#pragma once
enum InputFlags : unsigned short
{
	/* Controls */
	Up = 0x1,
	Down = 0x2,
	Left = 0x4,
	Right = 0x8,
	Shoot = 0x10,
	Roll = 0x20,
	/* Combinations */
	UpLeft = Up | Left,
	UpRight = Up | Right,
	DownLeft = Down | Left,
	DownRight = Down | Right,
};