import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class MarvellousService 
{
  // Dependency injection of HTTP
  constructor(private http : HttpClient) { }

  getBatches()
  {
    // It connects with Node_Express server
    return this.http.get("http://localhost:5100/getBatches");
  }
}
