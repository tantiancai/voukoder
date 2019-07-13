#include <string>
#include <Windows.h>

typedef int(*imp_init)();
typedef int(*imp_open_config_dialog)(std::string* settings, HWND hwnd);
typedef bool(*imp_encoder_open)(const char* settings);
typedef void(*imp_encoder_close)();

#define DYN(name) ((imp_##name)GetProcAddress(instance, #name))

int main()
{
	HMODULE instance = LoadLibraryA("C:\\Users\\Daniel\\source\\repos\\voukoder\\Voukoder\\x64\\Debug\\voukoder.dll");
	if (!instance)
	{
		exit(1);
	}

	// Init voukoder
	DYN(init)();

	std::string settings = "{ \"filename\" : \"c:\\\\Users\\\\Daniel\\\\Desktop\\\\file.mp4\", \"audio\" : {\"enabled\" : true } }";

	if (DYN(open_config_dialog)(&settings, GetDesktopWindow()))
	{
		OutputDebugStringA(settings.c_str());

		if (DYN(encoder_open)(settings.c_str()))
		{
			DYN(encoder_close);
		}
	}

	FreeLibrary(instance);
}