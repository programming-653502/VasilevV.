object OrderForm: TOrderForm
  Left = 200
  Top = 200
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Order'
  ClientHeight = 136
  ClientWidth = 342
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
    Left = 61
    Top = 60
    Width = 48
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object ConstLabel2: TLabel
    Left = 215
    Top = 60
    Width = 60
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
  end
  object ErrorLabel1: TLabel
    Left = 88
    Top = 114
    Width = 153
    Height = 13
    Caption = #1053#1077#1076#1086#1089#1090#1072#1090#1086#1095#1085#1086' '#1082#1085#1080#1075' '#1085#1072' '#1089#1082#1083#1072#1076#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object ErrorLabel2: TLabel
    Left = 76
    Top = 114
    Width = 169
    Height = 13
    Caption = #1055#1086#1078#1072#1083#1091#1081#1089#1090#1072' '#1079#1072#1087#1086#1083#1085#1080#1090#1077' '#1074#1089#1077' '#1087#1086#1083#1103'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object ErrorLabel3: TLabel
    Left = 121
    Top = 114
    Width = 78
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1072' '#1074#1074#1086#1076#1072'.'
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
  object NamesComboBox: TComboBox
    Left = 10
    Top = 83
    Width = 150
    Height = 21
    Style = csDropDownList
    TabOrder = 1
  end
  object NumberEdit: TEdit
    Left = 170
    Top = 83
    Width = 150
    Height = 21
    TabOrder = 2
  end
  object AddButton: TButton
    Left = 220
    Top = 10
    Width = 100
    Height = 30
    Caption = #1047#1072#1082#1072#1079#1072#1090#1100
    TabOrder = 3
    OnClick = AddButtonClick
  end
end
