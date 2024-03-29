// CShapeDlg.cpp: 实现文件
//
#pragma once
#include "stdafx.h"
#include"Shape.h"
#include "Drawing01.h"
#include "CShapeDlg.h"
#include "afxdialogex.h"
#include"CShapeDlg.h"
#include"Drawing01View.h"
// CShapeDlg 对话框

IMPLEMENT_DYNAMIC(CShapeDlg, CDialogEx)

CShapeDlg::CShapeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_x(0)
	
	, m_y(0)
	, m_width(0)
	, m_height(0)
	, m_PenWidth(0)
	, m_Type(0)
	, m_pen_type(0)
	
{

}

CShapeDlg::~CShapeDlg()
{
}

void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_LBIndex(pDX, IDC_LIST1, m_x);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_width);
	DDX_Text(pDX, IDC_EDIT4, m_height);
	DDX_Control(pDX, IDC_COMBO2, m_CmbShapeType);
	DDX_Text(pDX, IDC_EDIT5, m_PenWidth);
	DDX_Control(pDX, IDC_LIST7, m_LstPenType);
	DDX_Control(pDX, IDC_LIST8, m_LstBrushType);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_ColorPen);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_ColorBrush);
	//  DDX_CBIndex(pDX, IDC_COMBO2, m_Type);
	//  DDX_LBIndex(pDX, IDC_LIST7, m_pen_type);
	//  DDX_LBIndex(pDX, IDC_LIST7, m_pen_type);
	DDX_LBIndex(pDX, IDC_LIST7, m_pen_type);
	DDX_CBIndex(pDX, IDC_COMBO2, m_Type);
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &CShapeDlg::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CShapeDlg::OnCbnSelchangeCombo2)
	ON_LBN_SELCHANGE(IDC_LIST7, &CShapeDlg::OnLbnSelchangeList7)
	ON_LBN_SELCHANGE(IDC_LIST8, &CShapeDlg::OnLbnSelchangeList8)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CShapeDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CShapeDlg::OnBnClickedMfccolorbutton2)
	//ON_BN_CLICKED(IDC_IDOK, &CShapeDlg::OnBnClickedIdok)
	//ON_BN_CLICKED(IDC_BUTTON2, &CShapeDlg::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_IDOK, &CShapeDlg::OnClickedIdok)
	ON_BN_CLICKED(IDOK, &CShapeDlg::OnBnClickedOk)
	ON_BN_CLICKED(Cancel, &CShapeDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CShapeDlg 消息处理程序


void CShapeDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CShapeDlg::OnCbnSelchangeCombo2()
{
	int i = m_CmbShapeType.GetCurSel();
	Type = (ElementType)(i + 1);



	// TODO: 在此添加控件通知处理程序代码
}


void CShapeDlg::OnLbnSelchangeList7()
{
	BorderType = m_LstPenType.GetCurSel();

	// TODO: 在此添加控件通知处理程序代码
}


void CShapeDlg::OnLbnSelchangeList8()
{
	FillType = m_LstBrushType.GetCurSel();

	// TODO: 在此添加控件通知处理程序代码
}


void CShapeDlg::OnBnClickedMfccolorbutton1()
{
	BorderColor = m_ColorPen.GetColor();

	// TODO: 在此添加控件通知处理程序代码
}


void CShapeDlg::OnBnClickedMfccolorbutton2()
{
	FillColor = m_ColorBrush.GetColor();

	// TODO: 在此添加控件通知处理程序代码
}


BOOL CShapeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pComboBox->InsertString(0, _T("正方形"));
	pComboBox->InsertString(1, _T("矩形"));
	pComboBox->InsertString(2, _T("圆形"));
	pComboBox->InsertString(3, _T("椭圆形"));
	pComboBox->InsertString(4, _T("正三角形"));
	pComboBox->InsertString(5, _T("文本"));
	pComboBox->SetCurSel(0); // 将第一个作为默认选项
	//设置画笔风格列表框中的值

	 m_LstPenType.AddString(_T("PS_SOLID"));
	 m_LstPenType.AddString(_T("PS_DASH"));
	 m_LstPenType.AddString(_T("PS_DOT"));
	 m_LstPenType.AddString(_T("PS_DASHDOT"));
	 m_LstPenType.AddString(_T("PS_DASHDOTDOT"));
	 m_LstPenType.AddString(_T("PS_NULL"));
	//设置画刷样式列表框中的值
	m_LstBrushType.AddString("HS_HORIZONTAL");
	m_LstBrushType.AddString("HS_VERTICAL");
	m_LstBrushType.AddString("HS_FDIAGONAL");
	m_LstBrushType.AddString("HS_BDIAGONAL");
	m_LstBrushType.AddString("HS_CROSS");
	m_LstBrushType.AddString("HS_DIAGCROSS");

	if (pshape != NULL) 	ShapeToDlg();//pshape不为空代表修改图形操作，则将图形中的值设置到对话框的控件中
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


/*void CShapeDlg::OnBnClickedIdok()
{
	OnOK();
	// TODO: 在此添加控件通知处理程序代码
}*/


/*void CShapeDlg::OnBnClickedButton2()
{
	OnOK();
}*/
	// TODO: 在此添加控件通知处理程序代码

void CShapeDlg::DlgToShape()//将对话框中的数据设置到pshape所指的图形对象中
{
	if (pshape)
	{
		pshape->SetValue(Type, m_x, m_y, m_width, m_height);
		if (Type == TEXT) ((CText *)pshape)->SetText(m_text);
		pshape->SetPen(BorderColor, BorderType, m_PenWidth);
		pshape->SetBrush(FillColor, FillType);
	}

}
void CShapeDlg::ShapeToDlg()//将pshape所指的图形对象中数据设置到对话框中
{
	if (pshape != NULL)
	{
		pshape->GetBrush(FillColor, FillType);
		pshape->GetPen(BorderColor, BorderType, m_PenWidth);
		pshape->GetValue(Type, m_x, m_y, m_width, m_height);
	    if(Type==TEXT) ((CText *)pshape)->GetText (m_text);//绘制文字时，则获取文本
		m_CmbShapeType.SetCurSel((int)Type - 1);//根据Type设置组合框的选中项
		m_LstPenType.SetCurSel(BorderType);//根据BorderType值设置画笔风格类表框的选中项
		m_LstBrushType.SetCurSel(FillType);//根据FillType值设置画刷阴影列表框的选中项
		m_ColorPen.SetColor(BorderColor);//根据BorderColor值设置画笔颜色按钮的值
		m_ColorBrush.SetColor(FillColor);//根据FillColor值设置画刷颜色按钮的值
		UpdateData(false);
	}

}





void CShapeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CShapeDlg::OnBnClickedCancel()
{
	OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
