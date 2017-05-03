object HistoryForm: THistoryForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'History'
  ClientHeight = 153
  ClientWidth = 481
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BackButton: TButton
    Left = 0
    Top = 128
    Width = 471
    Height = 25
    Caption = #1053#1072#1079#1072#1076
    TabOrder = 0
    OnClick = BackButtonClick
  end
  object MainStringGrid: TStringGrid
    Left = 0
    Top = 0
    Width = 473
    Height = 128
    ColCount = 3
    DefaultColWidth = 150
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
