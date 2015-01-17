#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "GPIOManager.h"
#include "GPIOConst.h"
#include "Logger.h"


class Notifier
{
	private:
	GPIO::GPIOManager gp;
	
	public:
	
	static Notifier& getInstance()
	{
		static Notifier instance;
		return instance;
	}


	static void onRed()
	{
		Notifier::getInstance().gp.setValue(38, GPIO::HIGH);
		Logger::logMessage("turned on red LED");
	}
	
	void offRed()
	{
		Notifier::getInstance().gp.setValue(38, GPIO::LOW);
		Logger::logMessage("turned off red LED");
	}
	
	void onGreen()
	{
		Notifier::getInstance().gp.setValue(37, GPIO::HIGH);
		Logger::logMessage("turned on green LED");
	}
	
	void offGreen()
	{
		Notifier::getInstance().gp.setValue(37, GPIO::LOW);
		Logger::logMessage("turned off green LED");
	}
	
	void onYellow()
	{
		Notifier::getInstance().gp.setValue(39, GPIO::HIGH);
		Logger::logMessage("turned on yellow LED");
	}
	
	void offYellow()
	{
		Notifier::getInstance().gp.setValue(39, GPIO::LOW);
		Logger::logMessage("turned off yellow LED");
	}
	void mazeComplete(){}
	
};











#endif