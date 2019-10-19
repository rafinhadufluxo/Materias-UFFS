#ifndef RENDERPANEL_H
#define RENDERPANEL_H

#include <QtGui>
#include <Render.h>

class RenderPanel : public QWidget
{
    Q_OBJECT

private slots:
    void update(const QImage &);
    void recebeArquivo(const QString &);

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void atualizaMain(void);
    void atualizaTamanho(int , int);
    void enviaArquivo(const QString &);

public:
    RenderPanel(CommandQueue *c);

private:

    int screenW;
    int screenH;
    QLabel* fundolb;
    CommandQueue *cmdq;
    
};

#endif
