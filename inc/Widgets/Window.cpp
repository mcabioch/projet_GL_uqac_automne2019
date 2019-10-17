#include "Window.hpp"

Window::Window(QWidget *parent) :
	Widget(parent),

	m_Cache(nullptr),
	m_MainLayout(nullptr),
	m_TitleBar(nullptr),
	m_SizeGrip(nullptr),
	m_CenterLayout(nullptr),
	m_CenterWidget(nullptr),

	transparent(false),
	enabledResize(true),
	isFullscreen(false)
{
	m_MainLayout = new QGridLayout(this);
	m_CenterLayout = new QVBoxLayout;
	m_TitleBar = new WindowTitleBar(this);
	m_SizeGrip = new QSizeGrip(parent);

	connect(this, SIGNAL(WindowTitleChanged(QString)), m_TitleBar, SLOT(UpdateWindowTitle(QString)));
	connect(this, SIGNAL(WindowResizeChanged(bool)), m_TitleBar, SLOT(ApplyResizeChange(bool)));
	connect(this, SIGNAL(TitleBarShowState(bool)), m_TitleBar, SLOT(ApplyTitleBarState(bool)));

	connect(this, SIGNAL(Reduice()), m_TitleBar, SLOT(Minimized()));
	connect(this, SIGNAL(Fullscreen()), m_TitleBar, SLOT(Maximized()));
	connect(this, SIGNAL(Quit()), m_TitleBar, SLOT(Quit()));

	this->resize(512, 512);

	this->setWindowTitle(tr("Window"));
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setTransparency();

	m_MainLayout->setMargin(0);
	m_MainLayout->setSpacing(0);

	m_MainLayout->addWidget(m_TitleBar, 0, 0, 1, 1);

	m_MainLayout->setRowStretch(1, 1);

	this->setLayout(m_MainLayout);

	this->setMargin(1, 5, 5, 22);
	m_MainLayout->addLayout(m_CenterLayout, 1, 0, 1, 1);
}

Window::~Window(){
	deletePtr(m_Cache);
	deletePtr(m_CenterLayout);
	deletePtr(m_SizeGrip);
	deletePtr(m_TitleBar);
	deletePtr(m_MainLayout);
}

void Window::CenterOnScreen(){
	QDesktopWidget screen;
	QRect screenGeom = screen.screenGeometry(this);

	int screenCenterX = screenGeom.center().x();
	int screenCenterY = screenGeom.center().y();

	this->move(screenCenterX - width () / 2, screenCenterY - height() / 2);
}

void Window::setWindowTitle(const QString &title){
	QWidget::setWindowTitle(title);

	emit WindowTitleChanged(title);
}

void Window::setCentralWidget(QWidget* widget){
	deletePtr(m_CenterWidget);
	m_CenterWidget = widget;

	m_CenterLayout->addWidget(m_CenterWidget);
}

void Window::setMargin(int t, int r, int b, int l){
	if(m_CenterLayout == nullptr){ return; }

	m_CenterLayout->setContentsMargins(l, t, r, b);
}

void Window::setTransparency(){
	#if QT_VERSION >= 0x040500
		#ifdef Q_WS_X11
			if(x11Info().isCompositingManagerRunning()){
				this->setAttribute(Qt::WA_TranslucentBackground);
				this->transparent = true;
			}
		#else
			this->setAttribute(Qt::WA_TranslucentBackground);
			this->transparent = true;
		#endif
	#endif
}

void Window::useTransparency(){
	if(this->transparent){
		#if QT_VERSION >= 0x040500
			if(!this->testAttribute(Qt::WA_TranslucentBackground)){
				this->setMask(this->m_Cache->mask());
			}
		#else
			this->setMask(this->m_Cache->mask());
		#endif
	}
}

void Window::setSize(int w, int h){
	if(enabledResize){
		this->resize(w, h);
	} else {
		this->setFixedSize(w, h);
	}
}

void Window::enableResize(bool enable){
	enabledResize = enable;

	emit WindowResizeChanged(enable);

	this->setSize(this->width(), this->height());
}

void Window::showTitlebar(bool enable){
	emit TitleBarShowState(enable);
}

void Window::fullscreen(){
	isFullscreen = !isFullscreen;
	emit Fullscreen();
}

void Window::minimize(){
	emit Reduice();
}

void Window::quit(){
	emit Quit();
}
