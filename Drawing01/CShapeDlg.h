#pragma once
#include"Shape.h"
#include"Drawing01View.h"
#include"Drawing01Doc.h"
#include"Drawing01.h"
#include"CShapeDlg.h"
#include"stdafx.h"
//enum ElementType{ NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };


// CShapeDlg 对话框

class CShapeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeDlg)

public:
	CShapeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShapeDlg();
	void DlgToShape();//从对话框读取数据到图形对象中
	void ShapeToDlg();//从图形对象读取数据到对话框中

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	 
//	int m_Type;
//	int m_pen_type;
	int m_brush_type;
	COLORREF m_pen_color;
	COLORREF m_brush_color;
	int m_pen_width;
	int m_text;

	afx_msg void OnEnChangeEdit2();
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	CComboBox m_CmbShapeType;
	int m_PenWidth;
	CListBox m_LstPenType;
	CListBox m_LstBrushType;
	CMFCColorButton m_ColorPen;
	CMFCColorButton m_ColorBrush;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型实线、虚线、虚点线等	
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型
    ElementType Type;//图元类型
	CShape *pshape;//指向与对话框对应的图形对象

	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnLbnSelchangeList7();
	afx_msg void OnLbnSelchangeList8();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	virtual BOOL OnInitDialog();
	//afx_msg void OnBnClickedIdok();
	//afx_msg void OnBnClickedButton2();
	//afx_msg void OnClickedIdok();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
//	int m_Type;
//	int m_Type;
//	int m_Type;
	int m_Type;
//	int m_pen_type;
//	int m_pen_type;
//	int m_pen_type;
//	int m_pen_type;
	int m_pen_type;
//	int m_Type;
};
