object MainForm: TMainForm
  Left = 493
  Top = 305
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Menu'
  ClientHeight = 168
  ClientWidth = 210
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
  object DeliveryButton: TButton
    Left = 10
    Top = 10
    Width = 180
    Height = 30
    Caption = #1055#1086#1089#1090#1072#1074#1082#1072' '#1085#1072' '#1089#1082#1083#1072#1076
    TabOrder = 0
    OnClick = DeliveryButtonClick
  end
  object OrderButton: TButton
    Left = 10
    Top = 50
    Width = 180
    Height = 30
    Caption = #1047#1072#1082#1072#1079
    TabOrder = 1
    OnClick = OrderButtonClick
  end
  object StatisticsButton: TButton
    Left = 10
    Top = 90
    Width = 180
    Height = 30
    Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
    TabOrder = 2
    OnClick = StatisticsButtonClick
  end
  object ExitButton: TButton
    Left = 10
    Top = 130
    Width = 180
    Height = 30
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 3
    OnClick = ExitButtonClick
  end
end
