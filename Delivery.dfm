object DeliveryForm: TDeliveryForm
  Left = 200
  Top = 200
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Delivery'
  ClientHeight = 253
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object ConstLabel1: TLabel
    Left = 70
    Top = 60
    Width = 31
    Height = 13
    Caption = #1040#1074#1090#1086#1088
    Visible = False
  end
  object ConstLabel2: TLabel
    Left = 220
    Top = 60
    Width = 48
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    Visible = False
  end
  object ConstLabel3: TLabel
    Left = 390
    Top = 60
    Width = 28
    Height = 13
    Caption = #1046#1072#1085#1088
    Visible = False
  end
  object ConstLabel4: TLabel
    Left = 55
    Top = 124
    Width = 60
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
    Visible = False
  end
  object ConstLabel5: TLabel
    Left = 210
    Top = 124
    Width = 70
    Height = 13
    Caption = #1062#1077#1085#1072' '#1079#1072#1082#1091#1087#1082#1080
    Visible = False
  end
  object ConstLabel6: TLabel
    Left = 367
    Top = 124
    Width = 74
    Height = 13
    Caption = #1062#1077#1085#1072' '#1087#1088#1086#1076#1072#1078#1080
    Visible = False
  end
  object ErrorLabel1: TLabel
    Left = 137
    Top = 223
    Width = 216
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1072'. '#1055#1086#1078#1072#1083#1091#1081#1089#1090#1072' '#1079#1072#1087#1086#1083#1085#1080#1090#1077' '#1074#1089#1077' '#1087#1086#1083#1103'.'
    Color = clBackground
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object ErrorLabel2: TLabel
    Left = 208
    Top = 223
    Width = 74
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1072' '#1074#1074#1086#1076#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object MenuButton: TButton
    Left = 10
    Top = 10
    Width = 100
    Height = 30
    Caption = #1052#1077#1085#1102
    TabOrder = 0
    OnClick = MenuButtonClick
  end
  object OldButton: TButton
    Left = 170
    Top = 10
    Width = 150
    Height = 30
    Caption = #1042#1099#1073#1086#1088' '#1080#1079' '#1080#1084#1077#1102#1097#1080#1093#1089#1103
    TabOrder = 1
    OnClick = OldButtonClick
  end
  object NewButton: TButton
    Left = 330
    Top = 10
    Width = 150
    Height = 30
    Caption = #1053#1086#1074#1072#1103
    TabOrder = 2
    OnClick = NewButtonClick
  end
  object NamesComboBox: TComboBox
    Left = 170
    Top = 83
    Width = 150
    Height = 21
    Style = csDropDownList
    TabOrder = 3
    Visible = False
  end
  object AuthorEdit: TEdit
    Left = 10
    Top = 83
    Width = 150
    Height = 21
    TabOrder = 4
    Visible = False
  end
  object NameEdit: TEdit
    Left = 170
    Top = 83
    Width = 150
    Height = 21
    TabOrder = 5
    Visible = False
  end
  object GenreEdit: TEdit
    Left = 330
    Top = 83
    Width = 150
    Height = 21
    TabOrder = 6
    Visible = False
  end
  object NumberEdit: TEdit
    Left = 10
    Top = 147
    Width = 150
    Height = 21
    TabOrder = 7
    Visible = False
  end
  object InEdit: TEdit
    Left = 170
    Top = 147
    Width = 150
    Height = 21
    TabOrder = 8
    Visible = False
  end
  object OutEdit: TEdit
    Left = 330
    Top = 147
    Width = 150
    Height = 21
    TabOrder = 9
    Visible = False
  end
  object AddButton: TButton
    Left = 170
    Top = 188
    Width = 150
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 10
    Visible = False
    OnClick = AddButtonClick
  end
end
