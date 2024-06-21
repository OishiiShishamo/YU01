#include "text.h"

void text(std::string str, int color) {
	txt.eight = txt.seven;
	txt.seven = txt.six;
	txt.six = txt.five;
	txt.five = txt.four;
	txt.four = txt.three;
	txt.three = txt.two;
	txt.two = txt.one;
	txt.one = str;
	txt.color8 = txt.color7;
	txt.color7 = txt.color6;
	txt.color6 = txt.color5;
	txt.color5 = txt.color4;
	txt.color4 = txt.color3;
	txt.color3 = txt.color2;
	txt.color2 = txt.color1;
	txt.color1 = color;
}
void textbox() {
	SetFontSize(20);
	if (txt.flag == 1) {
		DrawRotaGraph(CENTERX, 800, 1.0, 0.0, GH[9], TRUE);
		switch (txt.color1) {
		case RED:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 0, 0), "%s", txt.one.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 720, GetColor(0, 128, 0), "%s", txt.one.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 720, GetColor(0, 0, 255), "%s", txt.one.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 165, 0), "%s", txt.one.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 255, 0), "%s", txt.one.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 720, GetColor(0, 255, 255), "%s", txt.one.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 720, GetColor(128, 0, 128), "%s", txt.one.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 0, 255), "%s", txt.one.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 720, GetColor(0, 255, 0), "%s", txt.one.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 255, 255), "%s", txt.one.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 720, GetColor(0, 0, 0), "%s", txt.one.c_str());
			break;
		defaulet:
			DrawFormatString(CENTERX - 280, 720, GetColor(255, 255, 255), "%s", txt.one.c_str());
			break;
		}
		switch (txt.color2) {
		case RED:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 0, 0), "%s", txt.two.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 740, GetColor(0, 128, 0), "%s", txt.two.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 740, GetColor(0, 0, 255), "%s", txt.two.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 165, 0), "%s", txt.two.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 255, 0), "%s", txt.two.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 740, GetColor(0, 255, 255), "%s", txt.two.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 740, GetColor(128, 0, 128), "%s", txt.two.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 0, 255), "%s", txt.two.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 740, GetColor(0, 255, 0), "%s", txt.two.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 255, 255), "%s", txt.two.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 740, GetColor(0, 0, 0), "%s", txt.two.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 740, GetColor(255, 255, 255), "%s", txt.two.c_str());
			break;
		}
		switch (txt.color3) {
		case RED:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 0, 0), "%s", txt.three.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 760, GetColor(0, 128, 0), "%s", txt.three.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 760, GetColor(0, 0, 255), "%s", txt.three.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 165, 0), "%s", txt.three.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 255, 0), "%s", txt.three.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 760, GetColor(0, 255, 255), "%s", txt.three.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 760, GetColor(128, 0, 128), "%s", txt.three.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 0, 255), "%s", txt.three.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 760, GetColor(0, 255, 0), "%s", txt.three.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 255, 255), "%s", txt.three.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 760, GetColor(0, 0, 0), "%s", txt.three.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 760, GetColor(255, 255, 255), "%s", txt.three.c_str());
			break;
		}
		switch (txt.color4) {
		case RED:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 0, 0), "%s", txt.four.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 780, GetColor(0, 128, 0), "%s", txt.four.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 780, GetColor(0, 0, 255), "%s", txt.four.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 165, 0), "%s", txt.four.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 255, 0), "%s", txt.four.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 780, GetColor(0, 255, 255), "%s", txt.four.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 780, GetColor(128, 0, 128), "%s", txt.four.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 0, 255), "%s", txt.four.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 780, GetColor(0, 255, 0), "%s", txt.four.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 255, 255), "%s", txt.four.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 780, GetColor(0, 0, 0), "%s", txt.four.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 780, GetColor(255, 255, 255), "%s", txt.four.c_str());
			break;
		}
		switch (txt.color5) {
		case RED:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 0, 0), "%s", txt.five.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 800, GetColor(0, 128, 0), "%s", txt.five.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 800, GetColor(0, 0, 255), "%s", txt.five.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 165, 0), "%s", txt.five.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 255, 0), "%s", txt.five.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 800, GetColor(0, 255, 255), "%s", txt.five.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 800, GetColor(128, 0, 128), "%s", txt.five.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 0, 255), "%s", txt.five.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 800, GetColor(0, 255, 0), "%s", txt.five.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 255, 255), "%s", txt.five.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 800, GetColor(0, 0, 0), "%s", txt.five.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 800, GetColor(255, 255, 255), "%s", txt.five.c_str());
			break;
		}
		switch (txt.color6) {
		case RED:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 0, 0), "%s", txt.six.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 820, GetColor(0, 128, 0), "%s", txt.six.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 820, GetColor(0, 0, 255), "%s", txt.six.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 165, 0), "%s", txt.six.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 255, 0), "%s", txt.six.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 820, GetColor(0, 255, 255), "%s", txt.six.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 820, GetColor(128, 0, 128), "%s", txt.six.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 0, 255), "%s", txt.six.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 820, GetColor(0, 255, 0), "%s", txt.six.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 255, 255), "%s", txt.six.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 820, GetColor(0, 0, 0), "%s", txt.six.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 820, GetColor(255, 255, 255), "%s", txt.six.c_str());
			break;
		}
		switch (txt.color7) {
		case RED:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 0, 0), "%s", txt.seven.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 840, GetColor(0, 128, 0), "%s", txt.seven.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 840, GetColor(0, 0, 255), "%s", txt.seven.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 165, 0), "%s", txt.seven.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 255, 0), "%s", txt.seven.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 840, GetColor(0, 255, 255), "%s", txt.seven.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 840, GetColor(128, 0, 128), "%s", txt.seven.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 0, 255), "%s", txt.seven.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 840, GetColor(0, 255, 0), "%s", txt.seven.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 255, 255), "%s", txt.seven.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 840, GetColor(0, 0, 0), "%s", txt.seven.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 840, GetColor(255, 255, 255), "%s", txt.seven.c_str());
			break;
		}
		switch (txt.color8) {
		case RED:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 0, 0), "%s", txt.eight.c_str());
			break;
		case GREEN:
			DrawFormatString(CENTERX - 280, 860, GetColor(0, 128, 0), "%s", txt.eight.c_str());
			break;
		case BLUE:
			DrawFormatString(CENTERX - 280, 860, GetColor(0, 0, 255), "%s", txt.eight.c_str());
			break;
		case ORANGE:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 165, 0), "%s", txt.eight.c_str());
			break;
		case YELLOW:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 255, 0), "%s", txt.eight.c_str());
			break;
		case AQUA:
			DrawFormatString(CENTERX - 280, 860, GetColor(0, 255, 255), "%s", txt.eight.c_str());
			break;
		case PURPLE:
			DrawFormatString(CENTERX - 280, 860, GetColor(128, 0, 128), "%s", txt.eight.c_str());
			break;
		case PINK:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 0, 255), "%s", txt.eight.c_str());
			break;
		case LIME:
			DrawFormatString(CENTERX - 280, 860, GetColor(0, 255, 0), "%s", txt.eight.c_str());
			break;
		case WHITE:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 255, 255), "%s", txt.eight.c_str());
			break;
		case BLACK:
			DrawFormatString(CENTERX - 280, 860, GetColor(0, 0, 0), "%s", txt.eight.c_str());
			break;
		default:
			DrawFormatString(CENTERX - 280, 860, GetColor(255, 255, 255), "%s", txt.eight.c_str());
			break;
		}
	}
	SetFontSize(60);
}
void text_clear() {
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
	text("", WHITE);
}