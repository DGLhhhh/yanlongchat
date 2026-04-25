#pragma once
#include "const.h"
// 添加ConfigMgr类用来读取和管理配置, 定义一个SectionInfo类管理key和value
struct SectionInfo {
	SectionInfo() {}
	~SectionInfo() {
		_section_datas.clear();
	}

	// 拷贝构造
	SectionInfo(const SectionInfo& src) {
		_section_datas = src._section_datas;
	}

	// 赋值
	SectionInfo& operator = (const SectionInfo& src) {
		if (&src == this) {
			return *this;
		}

		this->_section_datas = src._section_datas;
	}

	std::map<std::string, std::string> _section_datas;
	std::string  operator[](const std::string& key) {
		if (_section_datas.find(key) == _section_datas.end()) {
			return "";
		}
		// 这里可以添加一些边界检查  
		return _section_datas[key];
	}
};

class ConfigMgr
{
public:
	~ConfigMgr() {
		_config_map.clear();
	}
	SectionInfo operator[](const std::string& section) {
		if (_config_map.find(section) == _config_map.end()) {
			return SectionInfo(); // 如果没找到，先返回空的section
		}
		return _config_map[section];
	}

	static ConfigMgr& Inst()
	{
		static ConfigMgr cfg_mgr;
		return cfg_mgr;
	}

	ConfigMgr& operator=(const ConfigMgr& src) {
		if (&src == this) {
			return *this;
		}

		this->_config_map = src._config_map;
		return *this;
	};

	ConfigMgr(const ConfigMgr& src) {
		this->_config_map = src._config_map;
	}

	
private:
	ConfigMgr();

	// 存储section和key-value对的map  
	std::map<std::string, SectionInfo> _config_map;
};

