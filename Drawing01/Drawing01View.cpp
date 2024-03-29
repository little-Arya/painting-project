
// Drawing01View.cpp: CDrawing01View 类的实现
//

#include "stdafx.h"
#include"Shape.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing01.h"
#endif

#include "Drawing01Doc.h"
#include "Drawing01View.h"
#include"CShapeDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawing01View

IMPLEMENT_DYNCREATE(CDrawing01View, CScrollView)

BEGIN_MESSAGE_MAP(CDrawing01View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawing01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_Square, &CDrawing01View::OnSquare)
	//ON_COMMAND(ID_Rectangle, &CDrawing01View::OnRectangle)
	ON_WM_RBUTTONDBLCLK()
//	ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_Rectangle, &CDrawing01View::OnRectangle)
ON_COMMAND(ID_Circle, &CDrawing01View::OnCircle)
ON_COMMAND(ID_Triangle, &CDrawing01View::OnTriangle)
ON_COMMAND(ID_Ellipse, &CDrawing01View::OnEllipse)
ON_COMMAND(ID_Text, &CDrawing01View::OnText)
END_MESSAGE_MAP()

// CDrawing01View 构造/析构

CDrawing01View::CDrawing01View()
{
	// TODO: 在此处添加构造代码

}

CDrawing01View::~CDrawing01View()
{
}

BOOL CDrawing01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawing01View 绘图

void CDrawing01View::OnDraw(CDC* pDC)
{
	CDrawing01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0;i < pDoc->m_Elements.GetCount();i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
		p->Draw(pDC);
	}
	// TODO: 在此处为本机数据添加绘制代码
}

void CDrawing01View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawing01View 打印


void CDrawing01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawing01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawing01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawing01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawing01View::OnRButtonUp(UINT/* nFlags*/ , CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
	
}


void CDrawing01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawing01View 诊断

#ifdef _DEBUG
void CDrawing01View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawing01View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawing01Doc* CDrawing01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawing01Doc)));
	return (CDrawing01Doc*)m_pDocument;
}
#endif //_DEBUG


// CDrawing01View 消息处理程序


void CDrawing01View::OnSquare()
{
	
		static int StaticSquareX = 100, StaticSquareY = 100;
		CDrawing01Doc *pDoc = GetDocument();
		pDoc->m_Elements.Add(new CSquare(StaticSquareX, StaticSquareY, 100));
		StaticSquareX += 25, StaticSquareY += 50;
		pDoc->UpdateAllViews(NULL);
		// TODO: 在此添加命令处理程序代码
	
}




void CDrawing01View::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawing01Doc* pDoc = GetDocument();
	CShape *p;
	
	for (int i = pDoc->m_Elements.GetSize() - 1;i >= 0;i--)
	{

		p = (CShape *)pDoc->m_Elements[i];
		if (p->IsMatched(point))
		{
		
			pDoc->m_Elements.RemoveAt(i);
			pDoc->UpdateAllViews(NULL);
			break;
		}
	}
	CScrollView::OnRButtonDblClk(nFlags, point);
}




void CDrawing01View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		CDrawing01Doc* pDoc = GetDocument();
		CShape *p=NULL;
		CShapeDlg pshapedlg;
		pshapedlg.pshape = NULL;
		if (pshapedlg.DoModal() == IDOK)
		{
			switch (pshapedlg.Type)
			{
			case SQUARE:p = new CSquare; break;
			case RECTANGLE:p = new CRectangle;break;
			case TRIANGLE:p = new CTriangle;break;
			case CIRCLE:p = new Circle;break;
			case ELLIPSE:p = new CEllipse;break;
			case TEXT:p = new CText;break;
			}
			
			pDoc->m_Elements.Add(p);
			pshapedlg.pshape = p;
			pshapedlg.DlgToShape();
			pDoc->UpdateAllViews(NULL);
		}

	}
	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawing01View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawing01Doc *pDoc = GetDocument();
	CShape *p;
	for (int i = pDoc->m_Elements.GetSize() - 1;i >= 0;i--)
	{
		p = (CShape *)pDoc->m_Elements[i];
		if (p->IsMatched(point))
		{
			CShapeDlg pshapedlg;
			pshapedlg.pshape = p;
			if (pshapedlg.DoModal() == IDOK)
			{
				pshapedlg.DlgToShape();
				pDoc->UpdateAllViews(NULL);
			}
			break;
		}
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}


void CDrawing01View::OnRectangle()
{
	static int StaticSquareX = 300, StaticSquareY = 200;//设置长方形位置
	CDrawing01Doc *pDoc = GetDocument();
	pDoc->m_Elements.Add(new CRectangle(StaticSquareX, StaticSquareY, 100, 300));
	StaticSquareX += 25;//下一个正方形的长和宽
	StaticSquareY += 25;
	pDoc->UpdateAllViews(NULL);

	// TODO: 在此添加命令处理程序代码
}


void CDrawing01View::OnCircle()
{
	static int StaticSquareX = 100, StaticSquareY = 200;//设置圆形位置
	CDrawing01Doc *pDoc = GetDocument();
	pDoc->m_Elements.Add(new Circle(StaticSquareX, StaticSquareY, 100));
	StaticSquareX += 25;//下一个圆形的长和宽
	StaticSquareY += 25;
	pDoc->UpdateAllViews(NULL);

	// TODO: 在此添加命令处理程序代码
}


void CDrawing01View::OnTriangle()
{
	static int StaticSquareX = 200, StaticSquareY = 100;//设置三角形位置
	CDrawing01Doc *pDoc = GetDocument();
	pDoc->m_Elements.Add(new CTriangle(StaticSquareX, StaticSquareY, 100));
	StaticSquareX += 25;//下一个三角形的长和宽
	StaticSquareY += 25;
	pDoc->UpdateAllViews(NULL);

	// TODO: 在此添加命令处理程序代码
}


void CDrawing01View::OnEllipse()
{
	static int StaticSquareX = 500, StaticSquareY = 300;//设置圆形位置
	CDrawing01Doc *pDoc = GetDocument();
	pDoc->m_Elements.Add(new CEllipse(StaticSquareX, StaticSquareY, 100, 200));
	StaticSquareX += 25;//下一个圆形的长和宽
	StaticSquareY += 25;
	pDoc->UpdateAllViews(NULL);

	// TODO: 在此添加命令处理程序代码
}


void CDrawing01View::OnText()
{
	static int StaticSquareX = 200, StaticSquareY = 300;//设置圆形位置
	CDrawing01Doc *pDoc = GetDocument();
	pDoc->m_Elements.Add(new CText(StaticSquareX, StaticSquareY, 125, 45, "面向对象程序化编程"));
	StaticSquareX += 25;//下一个圆形的长和宽
	StaticSquareY += 25;
	pDoc->UpdateAllViews(NULL);

	// TODO: 在此添加命令处理程序代码
}
