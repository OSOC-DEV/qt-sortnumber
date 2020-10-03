#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "handlesort.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    HandleSort handleSort;
    QObject *toplevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(toplevel);
    QObject::connect(window, SIGNAL(submitTextField(QString)),
                         &handleSort, SLOT(handleSubmitTextField(QString)));
    QObject::connect(&handleSort, SIGNAL(setTextField(QVariant)),
                     window, SLOT(setTextField(QVariant)));

    return app.exec();
}
