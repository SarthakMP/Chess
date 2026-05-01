#pragma once
#include<Behavior.h>

class IconLoader : public BehaviorAdapter {
public:
	static inline std::vector<Texture2D> Images;
	static inline std::vector<std::string> ImagesPaths;
private:



	void LoadImages(std::string Path) {

		FilePathList ImageFiles = LoadDirectoryFilesEx(Path.c_str(), ".png", 0);
		Images.reserve(ImageFiles.count);
		for (size_t i = 0; i < ImageFiles.count; i++) {
			Images.push_back(LoadTexture(ImageFiles.paths[i]));
			ImagesPaths.push_back(ImageFiles.paths[i]);
		}
	}

	void Start() override {
		std::string Icon_path = "../../../res/Icons";
		LoadImages(Icon_path);
	}

	void Update() override {

	}

	
	
	
};
