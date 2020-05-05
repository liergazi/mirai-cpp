﻿#include <iostream>
// 使用静态库必须要在引入 mirai.h 前定义这个宏
#define MIRAICPP_STATICLIB
#include <mirai.h>

int main()
{
	using namespace std;
	using namespace Cyan;
	system("chcp 65001");
	MiraiBot bot("127.0.0.1", 539);
	while (true)
	{
		try
		{
			bot.Auth("INITKEY7A3O1a9v", 1589588851_qq);
			break;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		MiraiBot::SleepSeconds(1);
	}
	cout << "成功登录 bot。" << endl;

	bot.On<BotMuteEvent>(
		[&](BotMuteEvent e)
		{
			cout << "爷被禁言了!" << endl;
		});

	bot.On<BotUnmuteEvent>(
		[&](BotUnmuteEvent e)
		{
			bot.SendMessage(e.Operator.Group.GID,
				MessageChain().Plain("👴 出狱了!"));
		});

	bot.On<BotOnlineEvent>(
		[&](BotOnlineEvent e)
		{
			cout << "Bot "<< (int64_t)e.QQ <<" 主动登录事件" << endl;
		});

	bot.On<BotOfflineEventActive>(
		[&](BotOfflineEventActive e)
		{
			cout << "Bot " << (int64_t)e.QQ << " 主动下线事件" << endl;
		});

	bot.On<BotOfflineEventForce>(
		[&](BotOfflineEventForce e)
		{
			cout << "Bot " << (int64_t)e.QQ << " 被挤下线事件" << endl;
		});

	bot.On<BotOfflineEventDropped>(
		[&](BotOfflineEventDropped e)
		{
			cout << "Bot " << (int64_t)e.QQ << " 因网络原掉线事件" << endl;
		});

	bot.On<BotReloginEvent>(
		[&](BotReloginEvent e)
		{
			cout << "Bot " << (int64_t)e.QQ << " 重新登录事件" << endl;
		});

	bot.EventLoop();

	return 0;
}