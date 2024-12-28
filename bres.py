import math


def render_line(px, py, sx, sy)->None:
	dx = px - sx
	dy = py - sy
	if dx != 0:
		slope = dy / dx
	else
		slope = 0
	print(slope)


def main()->None:
	render_line(0, 0, 50 ,51)

main()