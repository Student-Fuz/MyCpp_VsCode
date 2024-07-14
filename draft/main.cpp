#include <QApplication>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QComboBox comboBox;
    comboBox.addItem("Option 1");
    comboBox.addItem("Option 2");
    comboBox.addItem("Option 3");

    // 使用样式表设置文本内容居中
    comboBox.setStyleSheet("QComboBox {"
                           "    text-align: center;"
                           "}");

    layout->addWidget(&comboBox);
    window.setLayout(layout);

    window.show();

    return app.exec();
}
