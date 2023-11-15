// StudentView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Student Details"

    Column {
        anchors.centerIn: parent

        Text {
            text: "Student Name: " + studentController.studentName
        }

        Text {
            text: "Student ID: " + studentController.studentId
        }
    }
}
