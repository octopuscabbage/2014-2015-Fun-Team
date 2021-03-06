#ifndef CONFIG_H
#define CONFIG_H

struct Configuration{
	int phase;
	int round;
	int startNode;
	int endNode;
	int boardXDimension;
	int boardYDimension;
	int matchTime;
};

class ConfigurationFactory{
	public:
		static Configuration* createConfiguration();
		static Configuration* constructBlankConfig();
};
#endif
