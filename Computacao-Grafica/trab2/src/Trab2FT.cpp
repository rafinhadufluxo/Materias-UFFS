#include <Trab2FT.h>
#include <MainWindow.h>

int Trab2FT::run(int argc, char* argv[])
{
    QApplication trab2FT(argc, argv);
    MainWindow *mwT2 = new MainWindow();

    mwT2->show();

    return trab2FT.exec();
}

int main(int argc, char* argv[])
{
    Trab2FT* t2 = new Trab2FT();
    return t2->run(argc, argv);
}
