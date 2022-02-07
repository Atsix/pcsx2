
#pragma once

#include "PadPS2.h"
#include "SioTypes.h"
#include <array>
#include <queue>

using PadPS2Array = std::array<std::array<std::unique_ptr<PadPS2>, MAX_SLOTS>, MAX_PORTS>;

class PadPS2Protocol
{
private:
	PadPS2Array pads;
	PadPS2* activePad = nullptr;
	PadPS2Mode mode = PadPS2Mode::NOT_SET;

	size_t GetResponseSize(PadPS2Type padPS2Type);
	
	void Mystery();
	void ButtonQuery();
	void Poll();
	void Config();
	void ModeSwitch();
	void StatusInfo();
	void Constant1();
	void Constant2();
	void Constant3();
	void VibrationMap();
	void ResponseBytes();

public:
	PadPS2Protocol();
	~PadPS2Protocol();

	void SoftReset();
	void FullReset();
	PadPS2Mode GetPadMode();
	PadPS2* GetPad(size_t port, size_t slot);
	void SetActivePad(PadPS2* pad);

	void SendToPad();
};

extern PadPS2Protocol g_PadPS2Protocol;