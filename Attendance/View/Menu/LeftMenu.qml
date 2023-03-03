import QtQuick 2.12
import QtQuick.Window 2.12

import "./"

Rectangle {
    visible: true

    property bool isOpend: false

    Image {
        x: 30
        y: 10
        width: 30
        height: 30
        source: (isOpend === true) ? "file:///D:/Attendance/Attendance/Image/icon_Button_Close.png" : "file:///D:/Attendance/Attendance/Image/icon_hamburger.png"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                toggle()
            }
        }
    }

    Image {
        y: 50
        width: parent.width
        height: 2
        source: "file:///D:/Attendance/Attendance/Image/icon_horizontal_line.png"
    }

    Rectangle {
        id: menuArea
        y: 52
        width: 300
        height: parent.height
        color: "#F8F8F8"
        visible: false

        LeftMenuListView { }
    }

    NumberAnimation {
        id: menuOpenAnimation
        target: menuArea
        property: "x"
        from: -300
        duration: 800
        to: 0
    }

    function toggle()
    {
        if(isOpend === true) {
            isOpend = false
            menuArea.visible = false
        }
        else {
            isOpend = true
            menuArea.visible = true
            menuOpenAnimation.start()
        }
    }
}
