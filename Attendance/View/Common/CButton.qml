import QtQuick 2.0
import QtQuick.Controls 2.12

Button {
    property string buttonText: ""
    property int textSize: 12

    width: parent.width
    height: parent.height

    Image {
        anchors.fill: parent
        source: "file:///D:/Attendance/Image/icon_hamburger.png"
    }

    Text {
        text: buttonText
        font.pixelSize: textSize
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
