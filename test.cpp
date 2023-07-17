
// PixelCapture\Private\PixelCaptureCapturerMultiFormat.cpp

int main(){
	// cache each layer size
	if (LayerSizes.IsEmpty())
	{
		const int Width = SourceFrame.GetWidth();
		const int Height = SourceFrame.GetHeight();

		double MaxLength = Width > Height ? Width : Height;
		LayerSizes.SetNum(LayerScales.Num());
		for (int i = 0; i < LayerScales.Num(); ++i)
		{
			if (LayerScales[i] * MaxLength > 4096)
			{
				LayerScales[i] = 4096 / MaxLength;
			}
			UE_LOG(LogPixelCapture, Warning, TEXT("Capture Scale %f"), LayerScales[i]);
			LayerSizes[i].X = StaticCast<int>(Width * LayerScales[i]);
			LayerSizes[i].Y = StaticCast<int>(Height * LayerScales[i]);
		}
	}

  return 0;
}
