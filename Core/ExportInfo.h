#pragma once

#include <wx/wx.h>
#include "lavf.h"
#include "OptionContainer.h"
#include "FilterConfig.h"
#include "json.hpp"

using namespace nlohmann;

struct ExportInfo
{
	wxString filename = wxEmptyString;
	wxString application = wxEmptyString;
	int passes = 0;

	struct Video
	{
		bool enabled = true;
		int width = 0;
		int height = 0;
		wxString id = wxEmptyString;
		OptionContainer options;
		OptionContainer sideData;
		FilterConfig filters;
		AVRational timebase = { 0, 0 };
		AVRational sampleAspectRatio = { 0, 0 };
		AVFieldOrder fieldOrder = AVFieldOrder::AV_FIELD_UNKNOWN;
		AVColorRange colorRange = AVColorRange::AVCOL_RANGE_UNSPECIFIED;
		AVColorSpace colorSpace = AVColorSpace::AVCOL_SPC_UNSPECIFIED;
		AVColorPrimaries colorPrimaries = AVColorPrimaries::AVCOL_PRI_UNSPECIFIED;
		AVColorTransferCharacteristic colorTransferCharacteristics = AVColorTransferCharacteristic::AVCOL_TRC_UNSPECIFIED;
		int64_t ticksPerFrame = 0;
	} video;

	struct Audio
	{
		bool enabled = true;
		wxString id = wxEmptyString;
		OptionContainer options;
		OptionContainer sideData;
		FilterConfig filters;
		AVRational timebase = { 0, 0 };
		uint64_t channelLayout = 0;
	} audio;

	struct Format
	{
		wxString id = wxEmptyString;
		bool faststart = false;
	} format;
};