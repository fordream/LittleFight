/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "VisibleRect.h"

USING_NS_CC;

Rect VisibleRect::s_visibleRect;

/*********************************************************************
** 功能：		获取界面矩形区域
** 输入参数：	无
** 返回值： 	无
** 修改记录：	
*********************************************************************/
void VisibleRect::lazyInit()
{
    // no lazy init
    // Useful if we change the resolution in runtime
    s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
}

/*********************************************************************
** 功能：		获取界面矩形区域
** 输入参数：	无
** 返回值： 	Rect：获取界面矩形区域
** 修改记录：	
*********************************************************************/
Rect VisibleRect::getVisibleRect()
{
    lazyInit();
    return s_visibleRect;
}

/*********************************************************************
** 功能：		获取界面矩形区域“左中”点
** 输入参数：	无
** 返回值： 	Point：“左中”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::left()
{
    lazyInit();
    return Point(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

/*********************************************************************
** 功能：		获取界面矩形区域“右中”点
** 输入参数：	无
** 返回值： 	Point：“右中”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::right()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

/*********************************************************************
** 功能：		获取界面矩形区域“中顶”点
** 输入参数：	无
** 返回值： 	Point：“中顶”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::top()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

/*********************************************************************
** 功能：		获取界面矩形区域“中底”点
** 输入参数：	无
** 返回值： 	Point：“中底”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::bottom()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

/*********************************************************************
** 功能：		获取界面矩形区域“中心”点
** 输入参数：	无
** 返回值： 	Point：“中心”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::center()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

/*********************************************************************
** 功能：		获取界面矩形区域“左上”点
** 输入参数：	无
** 返回值： 	Point：“左上”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::leftTop()
{
    lazyInit();
    return Point(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

/*********************************************************************
** 功能：		获取界面矩形区域“右上”点
** 输入参数：	无
** 返回值： 	Point：“右上”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::rightTop()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

/*********************************************************************
** 功能：		获取界面矩形区域原点
** 输入参数：	无
** 返回值： 	Point：原点
** 修改记录：	
*********************************************************************/
Point VisibleRect::leftBottom()
{
    lazyInit();
    return s_visibleRect.origin;
}

/*********************************************************************
** 功能：		获取界面矩形区域“右下”点
** 输入参数：	无
** 返回值： 	Point：“右下”点
** 修改记录：	
*********************************************************************/
Point VisibleRect::rightBottom()
{
    lazyInit();
    return Point(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}