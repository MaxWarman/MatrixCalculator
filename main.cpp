#include "cmainwindow.h"
#include "cmodel.h"
#include "ccontroller.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initiate MVC
    cMainWindow view;
    cModel model(&view);
    cController controller(&model, &view);
    view.setController(&controller);

    // Check which operations are possible depending on initial conditions
    model.CheckPossibleOperations();

    // Show application window
    view.show();

    return a.exec();
}
