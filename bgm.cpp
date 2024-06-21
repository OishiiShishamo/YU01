#include "bgm.h"

void bgm() {
	switch (bgm_num) {
	case 0:
		if (CheckSoundMem(BSH[0]) == 0)PlaySoundMem(BSH[0], DX_PLAYTYPE_LOOP);
		if (CheckSoundMem(BSH[1]) == 1)StopSoundMem(BSH[1]);
		if (CheckSoundMem(BSH[2]) == 1)StopSoundMem(BSH[2]);
		break;
	case 1:
		if (CheckSoundMem(BSH[1]) == 0)PlaySoundMem(BSH[1], DX_PLAYTYPE_LOOP);
		if (CheckSoundMem(BSH[0]) == 1)StopSoundMem(BSH[0]);
		if (CheckSoundMem(BSH[2]) == 1)StopSoundMem(BSH[2]);
		break;
	case 2:
		if (CheckSoundMem(BSH[2]) == 0)PlaySoundMem(BSH[2], DX_PLAYTYPE_LOOP);
		if (CheckSoundMem(BSH[0]) == 1)StopSoundMem(BSH[0]);
		if (CheckSoundMem(BSH[1]) == 1)StopSoundMem(BSH[1]);
		break;
	}
}