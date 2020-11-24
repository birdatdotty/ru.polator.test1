import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    title: qsTr("Hello World")
    id: main
    width: 1024
    height: 768

    GridLayout {
        id: grid
        anchors.fill: parent

        rows: 2
        columns: 5

        User {
             textPos: "1-1-1-1"
             user: qmlUser1
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.columnSpan: 1
             Layout.rowSpan: 1
             Layout.row: 1
             Layout.column: 1
        }

        User {
            textPos: "1-1-2-1"
            user: qmlUser2
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 1
        }

        Server {
             textPos: "2-2-1-2"
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.columnSpan: 2
             Layout.rowSpan: 2
             Layout.row: 1
             Layout.column: 2
        }

        User {
             textPos: "1-1-1-4"
             user: qmlUser3
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.columnSpan: 1
             Layout.rowSpan: 1
             Layout.row: 1
             Layout.column: 4
        }
        User {
             textPos: "1-1-2-3"
             user: qmlUser4
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.columnSpan: 1
             Layout.rowSpan: 1
             Layout.row: 2
             Layout.column: 4
        }
    }
}
