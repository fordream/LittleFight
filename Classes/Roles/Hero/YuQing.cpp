#include "YuQing.h"

USING_NS_CC;
using namespace cocostudio;

YuQing::YuQing(void)
{
}

YuQing::~YuQing(void)
{
}

/* public: Begin*/
/* public: End*/

/* protected: Begin */
/*********************************************************************
** 功能：		加载动画资源
** 输入参数：	无
** 返回值： 	无
** 修改记录：	
*********************************************************************/
void YuQing::loadArmature()
{
	m_stRoleInfo.arAnimate = Armature::create(m_strRoleName.c_str());
	if (NULL == m_stRoleInfo.arAnimate)
	{
		return;
	}

	this->addChild(m_stRoleInfo.arAnimate);

	/* 注册动画帧事件和动作回调函数 */
	m_stRoleInfo.arAnimate->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_0(YuQing::actionFrameEventCallFunc, this, std::placeholders::_1
		, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	m_stRoleInfo.arAnimate->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(YuQing::actionMovementCallFunc, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

/*********************************************************************
** 功能：		初始化技能飞行道具
** 输入参数：	无
** 返回值：		无
** 修改记录：	
*********************************************************************/
void YuQing::initFlightPropInfo()
{
	m_stYuQingProp[YuQing_Normal].strPath = getFlightPropPath() + "YuQing_AtkProp";
	m_stYuQingProp[YuQing_Normal].ptOffset = Point(100, 70) * m_fResScale;
	m_stYuQingProp[YuQing_Normal].iImgNum = 1;

	m_stYuQingProp[YuQing_S2Prop].strPath = getFlightPropPath() + "YuQing_S2Prop";
	m_stYuQingProp[YuQing_S2Prop].ptOffset = Point(0, 80) * m_fResScale;
	m_stYuQingProp[YuQing_S2Prop].iImgNum = 5;
}

/*********************************************************************
** 功能：		动作回调函数
** 输入参数：	
** 返回值： 	
** 修改记录：	
*********************************************************************/
void YuQing::actionMovementCallFunc(Armature *ar, MovementEventType type, const std::string& str)
{
	movement(str, type, 0.5f);
}

/*********************************************************************
** 功能：		帧事件
** 输入参数：	
** 返回值： 	无
** 修改记录：	
*********************************************************************/
void YuQing::actionFrameEventCallFunc(Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex)
{
	frameEvent(evt);

	bool bDown = false;
	if (evt == getFrameEventName(FrameEvent_Shot_FD))
	{
		bDown = true;
	}

	if ((evt == getFrameEventName(FrameEvent_Shot)) || (evt == getFrameEventName(FrameEvent_Shot_FD)))
	{
		if ((RoleAct_Attack == m_stRoleInfo.actSign) || (RoleAct_Twice_Atk == m_stRoleInfo.actSign) || 
		 	(RoleAct_Thrice_Atk == m_stRoleInfo.actSign))
		{
			NormalAttack(bDown);
		}

		if (RoleAct_SkillTwo == m_stRoleInfo.actSign)
		{
			SkillTwo();
		}
	}
}

/* 动作执行 Begin*/
/*********************************************************************
** 功能：		普通攻击第一击
** 输入参数：	无
** 返回值：		bool:true:动作执行成功
** 修改记录：	
*********************************************************************/
bool YuQing::runActionAttack()
{
	bool bRet = Role::runActionAttack();
	if (true == bRet)
	{
		playEffectOgg("C072");
	}

	return bRet;
}

/*********************************************************************
** 功能：		普通攻击第二击
** 输入参数：	无
** 返回值：		bool:true:动作执行成功
** 修改记录：	
*********************************************************************/
bool YuQing::runActionTwiceAtk()
{
	bool bRet = Role::runActionTwiceAtk();
	if (true == bRet)
	{
		playEffectOgg("C072");
	}

	return bRet;
}

/*********************************************************************
** 功能：		普通攻击第三击
** 输入参数：	无
** 返回值：		bool:true:动作执行成功
** 修改记录：	
*********************************************************************/
bool YuQing::runActionThriceAtk()
{
	bool bRet = Role::runActionThriceAtk();
	if (true == bRet)
	{
		playEffectOgg("C072");
	}

	return bRet;
}

/*********************************************************************
** 功能：		执行技能一
** 输入参数：	无
** 返回值： 	无
** 修改记录：	
*********************************************************************/
bool YuQing::runActionSkillOne()
{
	bool bRet = Role::runActionSkillOne();
	if (true == bRet)
	{
		playEffectOgg("021DD");
	}

	return bRet;
}

/*********************************************************************
** 功能：		执行技能二
** 输入参数：	无
** 返回值： 	无
** 修改记录：	
*********************************************************************/
bool YuQing::runActionSkillTwo()
{
	bool bRet = Role::runActionSkillTwo();
	if (true == bRet)
	{
		playEffectOgg("020JN");
	}

	return bRet;
}
/* 动作执行 End*/

/*********************************************************************
** 功能：		普通攻击
** 输入参数：	bool bDown : 击中是否倒地
** 返回值：		无
** 修改记录：	
*********************************************************************/
void YuQing::NormalAttack(bool bDown)
{
	FlightPropInfo info = {0};
	info.num = m_stYuQingProp[YuQing_Normal].iImgNum;
	memcpy(&(info.skillInfo), &m_stSkillInfo[m_stRoleInfo.actSign], sizeof(SkillInfo));

	auto yqProp = CommonProp::create(this, m_stYuQingProp[YuQing_Normal].strPath, info);
	if (NULL != yqProp)
	{
		yqProp->setScaleX(m_stRoleSubInfo.side/* * m_fResScale*/);
		//yqProp->setScaleY(m_fResScale);
		yqProp->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
		yqProp->setPropFlag(bDown);
		yqProp->setPropPosition(Point(-m_stYuQingProp[YuQing_Normal].ptOffset.x * m_stRoleSubInfo.side, m_stYuQingProp[YuQing_Normal].ptOffset.y));
		this->getParent()->addChild(yqProp);
		yqProp->runPropCollisionDetective(0.2f, Point(-m_stSkillInfo[m_stRoleInfo.actSign].xAtkDis * m_stRoleSubInfo.side, 0));
	}
}

/*********************************************************************
** 功能：		技能2
** 输入参数：	无
** 返回值：		无
** 修改记录：	
*********************************************************************/
void YuQing::SkillTwo()
{
	FlightPropInfo info = {0};
	info.num = m_stYuQingProp[YuQing_S2Prop].iImgNum;
	info.dur = 0.35f / m_stYuQingProp[YuQing_S2Prop].iImgNum;
	memcpy(&(info.skillInfo), &m_stSkillInfo[RoleAct_SkillTwo], sizeof(SkillInfo));

	auto yqProp = CommonProp::create(this, m_stYuQingProp[YuQing_S2Prop].strPath, info);
	if (NULL != yqProp)
	{
		yqProp->setScale(m_fResScale);
		yqProp->setAnchorPoint(Point::ANCHOR_MIDDLE);
		yqProp->setPropFlag(false, 0.15f);
		yqProp->setPropPosition(Point(-m_stYuQingProp[YuQing_S2Prop].ptOffset.x * m_stRoleSubInfo.side, m_stYuQingProp[YuQing_S2Prop].ptOffset.y));
		this->getParent()->addChild(yqProp);
		yqProp->runPropCollisionDetective(0.2f, Point(-m_stSkillInfo[RoleAct_SkillTwo].xAtkDis * m_stRoleSubInfo.side, 0));
	}
}
/* protected: End */