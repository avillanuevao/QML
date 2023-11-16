import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    property alias principalColumn: principalColumn
    width: 640
    height: 480
    visible: true
    title: qsTr("SceneA")

    ColumnLayout
    {
        objectName: "principal"
        id: principalColumn
        anchors.centerIn: parent
    }
}
