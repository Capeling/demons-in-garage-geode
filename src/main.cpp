#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <UIBuilder.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
	bool init() {
		if(!GJGarageLayer::init())
			return false;
		auto winSize = CCDirector::sharedDirector()->getWinSize();
		CCDictionary* stats = GameStatsManager::sharedState()->m_playerStats;
		int demonAmount = stats->valueForKey("5")->intValue();

		auto demonIcon = Build<CCSprite>::createSpriteName("diffIcon_06_btn_001.png")
			.parent(this)
			.scale({0.525})
			.anchorPoint({0.5, 0.5})
			.pos({winSize.width - 20, winSize.height - 114});
			
		auto demonLabel = Build<CCLabelBMFont>::create(std::to_string(demonAmount).c_str(), "bigFont.fnt")
			.pos({winSize.width - 36, winSize.height - 114})
			.anchorPoint({1, 0.5})
			.parent(this)
			.scale(0.45);

		return true;

	}
};